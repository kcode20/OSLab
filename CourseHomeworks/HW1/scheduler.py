#!/usr/bin/env python3

'''
    Scheduler - reads file, separates processes, add processes to ready queue, sends processes to CPU until fully executed.
'''


import socket;
import queue;

class PCB:
  def __init__(self, process_name, PID, state, priority, interruptable, est_total_run_time, est_remaining_run_time):
    self.process_name = process_name
    self.PID = PID
    self.state = state
    self.priority = priority
    self.interruptable = interruptable
    self.est_total_run_time = est_total_run_time
    self.est_remaining_run_time = est_remaining_run_time
  
  def __str__(self):
        return "%s,%s,%s,%s,%s,%s,%s" % (self.process_name, self.PID, self.state, self.priority, self.interruptable, self.est_total_run_time, self.est_remaining_run_time);


def connect(host, port):
    q = queue.Queue(maxsize=7);

    with open('processes.txt', 'rt') as infile:
        lines = infile.read().split('\n')

    for line in lines[:-1]:
      process = line.split(',');
      tempPCB = PCB(process[0], process[1], process[2], process[3], process[4], process[5], process[6]);
      q.put(tempPCB);


    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.connect((host, port));
        print('Connected to %s:%s' % (host, port));

        while q.qsize() > 0:
            message = str(q.get());
            print('\tSending:\t%s' % message);
            sock.send(message.encode('utf-8'));

            data = sock.recv(1024);
            recievedMessage = data.decode();
            process = recievedMessage.split(',');
            print('\tReceived:\t%s' % recievedMessage);
            if int(process[6]) < 0:
              print('the process is done.');
            else:
              tempPCB = PCB(process[0], process[1], process[2], process[3], process[4], process[5], process[6]);
              q.put(tempPCB);          


    print('Finished, connection closed.');


if __name__ == '__main__':

    host = '127.0.0.1'
    port = 9000

    connect(host, port)
