### Syncronization

Imagine you have two processes that have a shared variable

```c
int count = 5
```

Process1 increments the counter

```c
void P1 () {
  ...
  counter++
  ...
}
```

Process2 decrements the counter

```c
void P2 () {
  ...
  counter--
  ...
}
```

What do you expect `print(counter)` to be?
Because they run at the same time there exists a race condition. The outcome of the program can be a 4,5, or 6.

To avoid the race condition we need the following:

- Mutually Exclusion: only one process can be in the critical section at a time
- Progress: there is no deadlock
- Fairness: any process should be able to access the resource

#### Some solutions for the race conditons:

###### Using locks and unlocks

```c
void P0 {
  lock(i)
  counter++
  unlock(i)
}

void P1 {
  lock(i)
  counter++
  unlock(i)
}
```

The following example shows if we have mutual exclusiveness, and progress, but not fairness.

```c

int turn=1;
P0 {
  while(1){
    while(turn == 2);
    cs()
    turn == 2
  }
}

P1 {
  while(1){
    while(turn == 1);
    cs()
    turn == 1
  }
}

```

The following is an example of mutual exclusion not being applied, but we have fairness.

```c
bool p1_in_cs = p2_in_cs =false;

void P1 (){
  while(1){
      while(p2_in_cs);
      p1_in_cs=true
      cs()
      p2_in_cs == false
    }
}

void P2 () {
  while(1){
    while(p1_in_cs);
    p2_in_cs = true
    cs()
    p2_in_cs = false
  }
}
```

#### The Peterson's Solution

```c
bool p1_wants_to_go = p2_wants_to_go =false;

void P1 (){
  while(1){
      p1_wants_to_go = true;
      int favor = 2;
      while(p2_wants_to_go == true && favor == 2);
      cs()
      p1_wants_to_go = false
    }
}

void P2 () {
  while(1){
      p2_wants_to_go = true;
      int favor = 1;
      while(p1_wants_to_go == true && favor == 1);
      // cs()
      p1_wants_to_go = false
    }
}
```
