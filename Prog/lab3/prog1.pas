program Prog1;
type rad = file of integer;

procedure p(var f, g: rad);
var
    a: integer;
begin
    reset(f); { сбрасываем указатель в начало }
    while not eof(f) do
    begin
        read(f, a); { в цикле читаем число }
        if a >= 0 then write(g, a); { если оно неотрицательное -- записываем }
    end;

    { повторяем действия для отрицательных чисел }
    reset(f);
    while not eof(f) do
    begin
        read(f, a);
        if a < 0 then write(g, a);
    end;
    close(f);
end;

var
    f, g: rad;
    input: integer;
begin
    { вводим данные и записываем их в файл }
    assign (f, 'f.txt');
    rewrite(f);
    repeat
        write('Введите число (0 – конец ввода)– ');
        readln(input);
        write(f, input);
    until (input = 0);


    assign (g, 'g.txt');
    rewrite(g); { перезаписываем файл g }
    p(f, g); { вызов процедуры }

    { вывод файла }
    reset(g);
    while not eof(g) do begin
        read(g, input);
        writeln(input);
    end;

    close (f);
    close(g);
end.
