`timescale 1ns/1ps

module main(input clk,output reg[10:0] dout);
reg [7:0] r1 [0:255];
reg [7:0] r2 [0:255];
reg [7:0] r3 [0:255];
reg [10:0] Gx;
reg [10:0] Gy ;
reg [10:0] G [0:254];
//reg clk;
reg [31:0] i = 31'b0;
reg [31:0] done = 31'b0;
reg [7:0] pixel;
reg wea =  1'b0;
reg ena=1'b1;
wire [7:0] dina;
reg [15:0] addra = 16'b0;
reg [7:0] A00, A01, A02,A10,A11,A12,A20,A21,A22;
integer data,scan,final;

blk_mem_gen_0 input_data (
  .clka(clk),    // input wire clka
  .ena(ena),      // input wire ena
  .wea(wea),      // input wire [0 : 0] wea
  .addra(addra),  // input wire [15 : 0] addra
  .dina(dina),    // input wire [7 : 0] dina
  .douta(douta)  // output wire [7 : 0] douta
);

ila_0 your_instance_name (
	.clk(clk), // input wire clk


	.probe0(clk), // input wire [0:0]  probe0  
	.probe1(dina), // input wire [7:0]  probe1 
	.probe2(dout) // input wire [10:0]  probe2
);

always @(posedge clk) begin

if(i==254) begin
done=done +1;
i=0;
end

if(i<255) begin
r3[i]=r2[i];
r2[i]=r1[i];
r1[i]= dina; 
end


A00=r3[i-2];
A01=r3[i-1];
A02=r3[i];
A10=r2[i-2];
A11=r2[i-1];
A12=r2[i];
A20=r1[i-2];
A21=r1[i-1];
A22=r1[i];
if(done>1 && i>1) begin

Gx = r3[i] + - r3[i-2] + r2[i]*2 - r2[i-2]*2 +r1[i] - r1[i-2];
Gy = r3[i] - r1[i] + r3[i-1]*2 - r1[i-1]*2 + r3[i-2] - r1[i-2];

if(Gx[10] == 1) 
	Gx = ~Gx +1;
if(Gy[10] == 1)
	Gy = ~Gy + 1;

dout = Gx+Gy;
end
	i=i+1;
end
always @(posedge clk) begin
addra = addra + 16'b0000000000000001;
end

endmodule