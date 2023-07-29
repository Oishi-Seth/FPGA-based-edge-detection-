# FPGA Based Edge Detection Usiing Sobel Algorithm

### Theory:
Sobel Algorithm works by identifying the edges of an image and improving them so that they are easily identifiable. This creates a grayscale image where the edges are shown in a tone of white. 
The detection algorithm works by detecting a gradient change in the horizontal and vertical axes. We use 2 convolution filters to determine the magnitude of gradient.

<br/>

### Implementation:
#### On Zedboard:
1. First we implemented the Sobel Edge Detection algorithm in Vivado HLS. The IP was then exported to Vivado and created the block diagram.
2. AXI Stream was used to send the image bytes from PS to PL.
3. Image transmission was tried using UART. However, the Sobel Edge Detection IP could not be integrated with UART.

#### Basys3:
1. Using COE file, data pixels were stored in a Block RAM and Sobel Edge Detection Algorithm was used. However, the data we got from Block RAM does not support RGB or Grayscale format.

<br/>

### Below are the outputs when we ran Co-Simulation on Vivado HLS for the following test cases:
#### Test Case 1:
![alt text](https://github.com/Oishi-Seth/FPGA-based-edge-detection-/blob/main/Test_images/test_1.bmp)
#### Output 1:
![alt text](https://github.com/Oishi-Seth/FPGA-based-edge-detection-/blob/main/Result_images/op_1.bmp)
#### Test Case 2:
![alt text](https://github.com/Oishi-Seth/FPGA-based-edge-detection-/blob/main/Test_images/test_2.bmp)
#### Output 2:
![alt text](https://github.com/Oishi-Seth/FPGA-based-edge-detection-/blob/main/Result_images/op_2.bmp)
