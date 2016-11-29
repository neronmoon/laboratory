program Prog2;
function count(needle: integer; s: string) : integer;
  var 
    c: char;
    result: integer;
  begin
    { обнуляем переменную }
    result := 0;
    for c in s do { перебираем символы в строке, и если символ собпадает с переданной цифрой -- увеличиваем результат на 1 }
      if ord(c) - 48 = needle then inc(result);
    { возвращаем результат }
    count := result;
  end;
var
  i: integer;
  s: string;
begin
  { Ввод входных данных }
  write('Enter S: ');
  readln(s);
  for i := 0 to 9 do { Для [0..9] считаем результат и выводим }
    writeln(i, ' : ', count(i, s));
end.