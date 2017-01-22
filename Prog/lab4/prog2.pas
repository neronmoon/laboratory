uses crt,graph;
const { определение констант }
    a = 200;
    y_center = 240;
    x_center = 320;
var
    drive, mode, i, x, y, x2, y2: integer;
    t, formula: real;
begin
    { инициализация графического режима }
    drive := detect;
    initgraph(drive,mode,'c:\env\bp\bgi');
    setcolor(2); { ставим зеленый цвет из палитры }
    line(10, y_center, 630, y_center); { рисуем оси координат }
    line(x_center, 10, x_center, 470);
    setcolor(15); { ставим белый цвет }
    t := -a * sqrt(2); { начальная точка отсчета }

    y := 0; { считаем координаты начала графика}
    x := round(x_center + t);

    while t <= a * sqrt(2) do { цикл в области определения }
    begin
        { увеличиваем t, так как мы уже }
        { посчитали значения для предыдущего t }
        t := t + 1;
        { считаем значение подкоренного выражения }
        formula := sqrt(a * a * a * a + 4 * t * t * a * a) - t * t - a * a;
        if formula >= 0 then { sqrt принимает только неотрицательные значения }
        begin
            x2:= round(x_center + t); { считаем новые точки графика }
            y2 := round(sqrt(formula));
            line(x, y_center - y, x2, y_center - y2); { рисуем линии }
            line(x, y_center + y, x2, y_center + y2);
            x := x2; { перекидываем текущую точку в предыдущую }
            y := y2;
        end;
    end;
    line(x2, y_center - y2, x2, y_center); { дорисовываем график до оси x }
    line(x2, y_center + y2, x2, y_center);
    repeat until keypressed;
    closegraph;
end.