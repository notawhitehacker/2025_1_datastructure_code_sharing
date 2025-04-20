'''
pol1
-2.0 +1.0x^1 -1.0x^2 +3.2x^3 +6.7x^4 
pol2
+2.0 +5.0x^1 +6.7x^4 -3.0x^5 +0.8x^6 
pol1 after align
+6.7x^4 +3.2x^3 -1.0x^2 +1.0x^1 -2.0 
pol1(2) = 128.799997
pol1+pol2
+0.8x^6 -3.0x^5 +13.4x^4 +3.2x^3 -1.0x^2 +6.0x^1 
pol1-pol2
-0.8x^6 +3.0x^5 +3.2x^3 -1.0x^2 -4.0x^1 -4.0 

'''


import matplotlib.pyplot as plt
import numpy as np

   # Function to plot polynomial graph
def plot_polynomial(coefficients, name_list):
       # Generate x values
    x = np.linspace(-10, 10, 400)
       
    for i in range(4) :
        coef = coefficients[i]
        name = name_list[i]
        y = np.polyval(coef, x)       
        plt.plot(x, y, label=name)
 
    plt.title('Polynomial Graph')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.grid(True)
    plt.legend()

   # Save the plot as an image file
    plt.savefig('polynomial_graph.png')
    plt.close()

   # Example usage: Plotting a polynomial graph with coefficients [1, -3, 2] (i.e., x^2 - 3x + 2)
coefficients = [[6.7, 3.2, -1, 1, -2]
                ,[0.8, -3, 6.7, 0, 0, 5, 2]
                ,[0.8, -3, 13.4, 3.2, -1, 6, 0]
                ,[-0.8, 3, 0, 3.2, 1.0, -4, -4]]
name_list = ['pol1', 'pol2', 'pol1+pol2', 'pol1-pol2']
plot_polynomial(coefficients, name_list)


