from matplotlib import pyplot as plt
import math as m
def grad2rad(grad):
    return ((grad*m.pi)/200)

def rad2grad(rad):
    return ((rad*200)/m.pi)

def sinG(grad):
    return (m.sin(grad2rad(grad)))


amplitude = 600 # as the 50us timer overflows after 3600, it is prescaled by 3, thus overflow at 1200 on stm32f103c8t6 with cpu_clk at 72MHz
 
table=[]

for i in range(0,400):
    value=amplitude*(1+sinG(i))
    value=m.ceil(value)
    table.append(value)
    # print(value)
    # print(",\n")

print(table)
plt.plot(table)
plt.show()
