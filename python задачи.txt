1)
if __name__ == '__main__':
    print("Hello, World!")
    
2)
#!/bin/python3

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    n = int(input().strip())
    if n % 2 != 0:
        print("Weird")
    elif n % 2 == 0 and n in range(2, 6):
        print("Not Weird")
    elif n % 2 == 0 and n in range(6, 21):
        print("Weird")
    elif n % 2 == 0 and n > 20:
        print("Not Weird")


3)
if __name__ == '__main__':
    a = int(input())
    b = int(input())
    print (a+b)
    print (a-b)
    print (a*b)


4)
if __name__ == '__main__':
    a = int(input())
    b = int(input())
    print (a//b)
    print (a/b)

5)
if __name__ == '__main__':
    n = int(input())
    for i in range(n):
        if i >= 0:
            print(i**2)
