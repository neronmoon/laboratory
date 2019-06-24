#!/usr/bin/env python3

import threading
import time
import random


class Queue:
    def __init__(self):
        self.q = []
        self.lock = threading.Lock()

    def get(self):
        self.lock.acquire()
        item = self.q.pop()
        self.lock.release()
        return item

    def put(self, item):
        self.lock.acquire()
        self.q.append(item)
        self.lock.release()

    def empty(self):
        self.lock.acquire()
        is_empty = len(self.q) == 0
        self.lock.release()
        return is_empty


task_queue = Queue()


def examinate(name):
    protocol = []
    print("{0} = (Wait -> (Student.N -> (Score.X -> {0}|Stop -> СТОП)))".format(name, ))
    while True:
        protocol.append("Wait")
        if task_queue.empty():
            protocol.append("Stop")
            break
        student = task_queue.get()
        protocol.append(student)

        time.sleep(random.randint(1, 3))
        score = random.randint(2, 5)

        protocol.append("Score.%s" % score)

    print("%s protocol: <" % name, ", ".join(protocol), ">")


def main():
    student_count = 10
    examinator_count = 3
    for i in range(student_count):
        task_queue.put("Student.%s" % i)

    for i in range(examinator_count):
        thread_name = "E%s" % i
        thread = threading.Thread(target=examinate, args=(thread_name, ))
        alphabet = ["Wait", "Stop"]
        for i in range(student_count):
            alphabet.append("Student.%s" % i)
        for i in range(2, 6):
            alphabet.append("Score.%s" % i)
        print("a%s = {" % thread_name, ", ".join(alphabet), "}")
        thread.start()


main()
