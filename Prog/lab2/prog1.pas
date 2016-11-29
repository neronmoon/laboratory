program Prog1;
type matrix = array [1..40, 1..40] of integer;
var
  m, n, i, j, maxi, maxj, maxij: Integer;
  mat: matrix;

begin
  { Вводим данные }
  write('Enter m: ');
  readln(m);

  write('Enter n: ');
  readln(n);

  writeln('Enter matrix');
  for i := 1 to m do 
    for j := 1 to n do 
      read(mat[i,j]);
  writeln; 
  
  maxi := 1;
  maxj := 1;
  maxij := mat[1,1]; { Вначале считаем наибольшим элемент [1,1] }
  for i := 1 to m do
      for j := 1 to n do begin { Проходим матрицу }
        if mat[i,j] > maxij then begin
          { Если текущий элемент больше maxij -- запоминаем его координаты и значение }
          maxij := mat[i,j];
          maxi := i;
          maxj := j;
        end;
      end;
  { Выводим результат }
  writeln('Max element in [', maxi, ', ', maxj, '] ');
end.
