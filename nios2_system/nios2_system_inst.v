	nios2_system u0 (
		.clk_clk                           (<connected-to-clk_clk>),                           //                        clk.clk
		.reset_reset_n                     (<connected-to-reset_reset_n>),                     //                      reset.reset_n
		.led_external_connection_export    (<connected-to-led_external_connection_export>),    //    led_external_connection.export
		.key_external_connection_export    (<connected-to-key_external_connection_export>),    //    key_external_connection.export
		.sw_external_connection_export     (<connected-to-sw_external_connection_export>),     //     sw_external_connection.export
		.hex3_0_external_connection_export (<connected-to-hex3_0_external_connection_export>), // hex3_0_external_connection.export
		.hex5_4_external_connection_export (<connected-to-hex5_4_external_connection_export>)  // hex5_4_external_connection.export
	);

