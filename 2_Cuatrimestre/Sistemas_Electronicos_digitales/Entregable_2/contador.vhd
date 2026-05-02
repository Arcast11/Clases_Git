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

    component fft_preset
        port (clk       : in std_logic;
              ce        : in std_logic;
              preset    : in std_logic;
              t         : in std_logic;
              q         : out std_logic);

    end component;

    component fft_reset
        port (clk       : in std_logic;
              ce        : in std_logic;
              reset    : in std_logic;
              t         : in std_logic;
              q         : out std_logic);

    end component;

    component ffd_preset
        port (clk       : in std_logic;
              ce        : in std_logic;
              preset     :in std_logic;
              d         : in std_logic;
              q         : out std_logic);

    end component;

    signal qa, qb, qc, qd : std_logic;
    signal da, db, tc, td : std_logic;

begin

    unitA : ffd_reset
        port (clk       => clk,
              ce        => ce,
              reset     => reset,
              d         => da,
              q         => qa);
    unitB : ffd_preset
        port (clk       => clk,
              ce        => ce,
              preset    => preset,
              d         => db,
              q         => qb);
    unitc : fft_preset
        port (clk       => clk,
              ce        => ce,
              preset    => preset,
              d         => tc,
              q         => qc);
    unitD : fft_preset
        port (clk       => clk,
              ce        => ce,
              preset    => preset,
              d         => td,
              q         => qd);


    td <= (not qb and qc and qd);
    tc <= (qa and not qc and not qb) or (qb and not qc) or (not qa and not qc and qd);
    db <= (not qb and not qc and not qd) or (not qa and not qc and qd);
    da <= (qb and not qc) or (not qa and qb) or (qc and qd);

    count   <= qa & qb & qc & qd;
    
end Behavioral;