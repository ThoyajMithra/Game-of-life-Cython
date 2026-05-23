import matplotlib.pyplot as plt
import numpy as np


x = y = 10
world = np.zeros((x, y))

# Create the figure and axis
fig, ax = plt.subplots()
# display the grid (origin='upper' matches matrix indexing)
im = ax.imshow(world, cmap='binary', vmin=0, vmax=1)

# Draw grid lines to see individual pixels easily
ax.set_xticks(np.arange(-0.5, x, 1), minor=True)
ax.set_yticks(np.arange(-0.5, y, 1), minor=True)
ax.grid(which='minor', color='gray', linestyle='-', linewidth=0.5)

def on_click(event):
    # Check if the click happened inside the grid area
    if event.xdata is not None and event.ydata is not None:
        # Convert click coordinates to nearest integer matrix indices
        col = int(round(event.xdata))
        row = int(round(event.ydata))
        
        # Ensure the click is within the boundary array limits
        if 0 <= row < y and 0 <= col < x:
            # Set the pixel value to 1
            world[row, col] = 1
            # Update the displayed image data
            im.set_data(world)
            # Redraw the canvas to show the changes immediately
            fig.canvas.draw()

# Connect the click event to our function
fig.canvas.mpl_connect('button_press_event', on_click)

plt.show()


f_w = list(world.astype(int).flatten())




from wrapper import PyLife
import time

game=PyLife(x,y,f_w)

fig_sim, ax_sim = plt.subplots()
im_sim = ax_sim.imshow(world, cmap='binary')


for i in range(20):
    res = game.generation()
    f_i = np.array(res).reshape(x, y)
    
    im_sim.set_data(f_i)
    plt.pause(0.2)

