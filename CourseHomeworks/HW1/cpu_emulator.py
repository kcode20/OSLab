#!/usr/bin/env python3

'''
    CPU Emulator - listens for processes to executes, accepts processes, processes it for 200 cycles, sends back to Scheduler.
'''


import socket


def listen(host, port):

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.bind((host, port))
        sock.listen()

        print('Listening on %s:%s' % (host, port))

        conn, addr = sock.accept()

        with conn:
            print('Connection from:', addr)

            while True:
                data = conn.recv(1024)

                if not data:
                    break
                else:
                    print('\tExecuting:\t%s' % data.decode())
                    data = data.decode().split(',')
                    remaining_time = int(data[6])
                    remaining_time -= 200;
                    data = ','.join(data[:6]) + ',' + str(remaining_time)
                    print('\tSending back to Scheduler:\t%s' % data)
                    conn.send(data.encode('utf-8'))

            print('Connection closed to:', addr)


if __name__ == '__main__':

    host = '127.0.0.1'
    port = 9000

    listen(host, port)
