uses crt,graph;
const
    a = 200;
    y_center = 240;
    x_center = 320;
var
    drive, mode, i, x, y, x2, y2: integer;
    t, formula: real;
begin
    drive := detect;
    initgraph(drive,mode,'c:\env\bp\bgi');
    setcolor(2);
    line(10, y_center, 630, y_center);
    line(x_center, 10, x_center, 470);
    setcolor(15);
    t := -a * sqrt(2);
    y := round(sqrt(formula));
    x := round(x_center + t);

    while t <= a * sqrt(2) do
    begin
        t := t + 0.2;
        formula := sqrt(a * a * a * a + 4 * t * t * a * a) - t * t - a * a;
        if formula >= 0 then
        begin
            x2:= round(x_center + t);
            y2 := round(sqrt(formula));
            line(x, y_center - y, x2, y_center - y2);
            line(x, y_center + y, x2, y_center + y2);
            x := x2;
            y := y2;
        end;
    end;
    repeat until keypressed;
    closegraph;
end.