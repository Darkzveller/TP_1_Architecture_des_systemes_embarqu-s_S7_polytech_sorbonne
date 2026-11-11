	component nios2_system is
		port (
			clk_clk                           : in  std_logic                     := 'X';             -- clk
			reset_reset_n                     : in  std_logic                     := 'X';             -- reset_n
			led_external_connection_export    : out std_logic_vector(9 downto 0);                     -- export
			key_external_connection_export    : in  std_logic_vector(1 downto 0)  := (others => 'X'); -- export
			sw_external_connection_export     : in  std_logic_vector(9 downto 0)  := (others => 'X'); -- export
			hex3_0_external_connection_export : out std_logic_vector(31 downto 0);                    -- export
			hex5_4_external_connection_export : out std_logic_vector(15 downto 0)                     -- export
		);
	end component nios2_system;

	u0 : component nios2_system
		port map (
			clk_clk                           => CONNECTED_TO_clk_clk,                           --                        clk.clk
			reset_reset_n                     => CONNECTED_TO_reset_reset_n,                     --                      reset.reset_n
			led_external_connection_export    => CONNECTED_TO_led_external_connection_export,    --    led_external_connection.export
			key_external_connection_export    => CONNECTED_TO_key_external_connection_export,    --    key_external_connection.export
			sw_external_connection_export     => CONNECTED_TO_sw_external_connection_export,     --     sw_external_connection.export
			hex3_0_external_connection_export => CONNECTED_TO_hex3_0_external_connection_export, -- hex3_0_external_connection.export
			hex5_4_external_connection_export => CONNECTED_TO_hex5_4_external_connection_export  -- hex5_4_external_connection.export
		);

