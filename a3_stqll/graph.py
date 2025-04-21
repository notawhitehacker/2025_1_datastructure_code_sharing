
import matplotlib.pyplot as plt
import numpy as np

# Function to plot polynomial graph
def plot_polynomial(coefficients):
    # Generate x values
    x = np.linspace(-10, 10, 400)
    
    # Calculate y values based on polynomial coefficients
    y = np.polyval(coefficients, x)
    
    # Plot the graph
    plt.plot(x, y)
    plt.title('Polynomial Graph')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.grid(True)
    plt.show()

# Example usage: Plotting a polynomial graph with coefficients [1, -3, 2] (i.e., x^2 - 3x + 2)
coefficients = [1, -3, 2]
plot_polynomial(coefficients)
