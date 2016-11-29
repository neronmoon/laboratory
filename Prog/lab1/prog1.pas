program Prog1;
var
  n, m, i, result: Integer;
begin
  { Ввод входных данных }
  write('Enter n: ');
  readln(n);
  write('Enter m: ');
  readln(m);
  { Обнуляем переменные }
  result := 0;
  
  for i := 1 to m do begin { m-раз }
    result := result + n mod 10; { Получаем последнюю цифру N, суммируем результат }
    n := n div 10; { Удаляем послеюнюю цифру N }
  end;

  { Выводим результат }
  writeln(result);
end.