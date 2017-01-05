program Prog2;
function letter(s: string; i: integer) : integer;
const
    letters = ['a'..'z', 'A'..'Z']; { алфавит }
var
    count: integer;
begin
    if s[i] in letters then count := 1 else count := 0; { если s[i] это буква -- будем прибавлять 1 иначе 0 }
    if i < length(s) then count := count + letter(s, i + 1); { складываем текущий результат и рекурсивно вызываем себя }

    letter := count; { возвращаем результат }
end;

var
    s: string;
begin
    Write('Enter string: ');
    read(s);
    WriteLn('Letters count: ', letter(s, 0)) { вызов функции. начинаем считать с 0-го символа }
end.
