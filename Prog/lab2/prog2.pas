program Prog2;
var
  s: string;
  c: char;
  alphabet: set of 'a'..'z';
begin
  for c:='a' to 'z' do { заполняем алфавит }
  	include(alphabet, c);
  write('Enter s: ');
  readln(s); { Читаем строку }
  for c in s do { пробегаем строку и удаляем из алфавита буквы, сходящие в строку}
  	exclude(alphabet, c); 
  for c in alphabet do { выводим результат }
  	write(c);
end.