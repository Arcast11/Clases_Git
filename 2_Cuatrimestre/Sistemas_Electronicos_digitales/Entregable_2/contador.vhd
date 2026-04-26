library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity contador37 is
    Port (
        clk   : in  STD_LOGIC;
        reset : in  STD_LOGIC;
        ce    : in  STD_LOGIC;
        count : out STD_LOGIC_VECTOR(3 downto 0)
    );
end contador37;

architecture Behavioral of contador37 is
    signal QA, QB, QC, QD : STD_LOGIC;
    signal DA, DB, TC, TD : STD_LOGIC;
begin

    -- Funciones lógicas
    DA <= QB and QC and QD;
    DB <= (not QA and not QC) or (QA and not QB);
    TC <= (not QB) or (QC and QD);
    TD <= QB and not QC;

    -- Biestables D
    process(clk, reset)
    begin
        if reset = '1' then
            QA <= '0';
            QB <= '0';
        elsif rising_edge(clk) then
            if ce = '1' then
                QA <= DA;
                QB <= DB;
            end if;
        end if;
    end process;

    -- Biestables T
    process(clk, reset)
    begin
        if reset = '1' then
            QC <= '0';
            QD <= '0';
        elsif rising_edge(clk) then
            if ce = '1' then
                QC <= QC xor TC;
                QD <= QD xor TD;
            end if;
        end if;
    end process;

    count <= QA & QB & QC & QD;

end Behavioral;