#include <stdlib.h>
#include "xil_types.h"
#include "xuartps.h"
#include "xparameters.h"

#define imageSize 240*240
#define headerSize 1080
#define fileSize imageSize+headerSize

int main() {
    u8 *imageData;
    u32 status;
    u32 receivedBytes = 0;
    u32 totalReceivedBytes = 0;
    u32 transmittedBytes = 0;
    u32 totalTransmittedBytes = 0;
    XUartPs_Config *myUartConfig;
    XUartPs myUart;
    imageData = malloc(sizeof(u8)*(fileSize));
    myUartConfig = XUartPs_LookupConfig(XPAR_UART_1_DEVICE_ID);
    status = XUartPs_CfgInitialize(&myUart, myUartConfig, myUartConfig->BaseAddress);
    if (status != XST_SUCCESS)
        printf("Uart initialisation failed \n\r");

    status = XUartPs_SetBaudRate(&myUart, 115200);
    if (status != XST_SUCCESS)
        printf("Baudrate init failed \n\r");

while (totalReceivedBytes < fileSize) {
        receivedBytes = XUartPs_Recv(&myUart, (u8*)&imageData[totalReceivedBytes], 100);
        totalReceivedBytes += receivedBytes;
    }
    // Read data from DDR, process it, store it back in DDR
    //
    //
    ////////////////////////////
    //
    // Enter Sobel Edge Detection IP related logic
    //
    ///////////////////////////
    //
    // Send data back to the computer
    while (totalTransmittedBytes < fileSize) {
        transmittedBytes = XUartPs_Send(XUartPs *InstancePtr, u8 *BufferPtr, u32 NumBytes);
        totalTransmittedBytes += transmittedBytes
    }
}
