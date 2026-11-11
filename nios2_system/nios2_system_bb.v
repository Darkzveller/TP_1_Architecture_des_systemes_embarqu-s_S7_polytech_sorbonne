
module nios2_system (
	clk_clk,
	reset_reset_n,
	led_external_connection_export,
	key_external_connection_export,
	sw_external_connection_export,
	hex3_0_external_connection_export,
	hex5_4_external_connection_export);	

	input		clk_clk;
	input		reset_reset_n;
	output	[9:0]	led_external_connection_export;
	input	[1:0]	key_external_connection_export;
	input	[9:0]	sw_external_connection_export;
	output	[31:0]	hex3_0_external_connection_export;
	output	[15:0]	hex5_4_external_connection_export;
endmodule
