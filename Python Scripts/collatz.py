#a python file to find a suitably difficult argument for the collatz conjecture

steps = input("Number of steps: ")

def collatz(x):
    if(x == 1):
        return 0
    if((x % 2) == 0):
        return 1 + collatz(x/2)
    else:
        return 1 + collatz(3*x+1)
i = 0;
n = 0;
steps = int(steps)
while(i < steps):
    n += 1
    i = collatz(n)
i = str(i)
n = str(n)
steps = str(steps)
print("The lowest number with greater than or equal to " + steps + " steps is " + n + " with " + i + " steps.")
#this is cool, but I wrote an assembly program that can do this much faster.