# Linetech-test-2021

Hi,

Fork this repository. Answers for every question should be placed in separate directories, named the same as the task number. Hyperlink to your fork of this repository will be treated as an answer.

If you don’t know what ‘fork’ is or you are not able to upload answers to (any) git-enabled platform, e.g. GitHub, GitLab. Then download the repository as a .zip file and send it back to us with answers, packed as .zip, to mateusz.ciolkosz@linetech.pl


## Task 1

Write a program, in C++ language, that launches two separate threads, using std::async. The first thread will have to return the arithmetic average of the dataset, and the second one should return the median value. Threads should be running in parallel. When return values from threads are collected, the main thread has to compare them and write to standard output which of them is bigger. Input data is in “1/data.txt”.


## Task 2

Imagine there is a robotic arm, e.g. Universal Robots UR10, with a laser distance sensor attached to its end effector. Let assume that the robotic arm base link is at the origin of a coordinate system. Describe how to calculate distance from the point that was measured by the sensor, to the robotic arm base link.


## Task 3

Choose a method of communication, that is available in ROS (Robot Operating System), best suited for broadcasting some sensor data, and one that is best for sharing low latency mathematical function capabilities. Explain your position.

## Task 4

What the return value of the program below is, assuming it was written in C17 language. Explain why.

```c
int main(void){
  char x = ' ' * 12;
  return x;
}
```

## Task 5

Write template class definition in language C++17. Class should:

- have template type parameter n, assume that n will be always a trivial type,
- have private data member 'x' of type n,
- have public reference getter for 'x' member,
- be default constructible,
- be copy and move assignable/constructable. 

## Disclaimer

If you cannot answer some of the above questions, don’t worry. We will consider each replay sent.



**Good luck**

***LT Team***



