library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity sistema37_tb is
end sistema37_tb;

architecture Behavioral of sistema37_tb is
    signal clk, reset, ce : STD_LOGIC := '0';
    signal count : STD_LOGIC_VECTOR(3 downto 0);
begin

    uut: entity work.contador37
        port map (
            clk   => clk,
            reset => reset,
            ce    => ce,
            count => count
        );

    -- Clock
    clk <= not clk after 10 ns;

    process
    begin
        reset <= '1';
        ce <= '0';
        wait for 20 ns;

        reset <= '0';
        ce <= '1';

        wait for 200 ns;
        reset <= '1';
        wait for 20 ns;

        wait;
    end process;

end Behavioral;