library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity sistema37_tb is
end sistema37_tb;

architecture Behavioral of sistema37_tb is

    component contador37
        port (clk       : in std_logic
              reset     : in std_logic 
              ce        : in std_logic 
              count     : out STD_LOGIC_VECTOR(3 downto 0));
    end component;

    signal clk      : std_logic := '0';
    signal reset    : std_logic := '0';
    signal ce       : std_logic := '0';
    signal count    : std_logic_vector (3 downto 0);

begin

    dut : contador37
    port map    (clk    => clk,
                 reset  => reset,
                 ce     => ce,
                 count  => count);
    
    clk <= not clk after 10ns;

    stimuli : process

    begin
    
        ce <= '0'; reset <= '1';
        wait for 100ns;
        reset <= '0';
        wait for 100 ns;
        ce <= '1';
        wait; 
        end process;


end Behavioral;