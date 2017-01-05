program Prog1;

type
    list = ^node_data;
    node_data = record
        data: integer;
        next: list
    end;

procedure remove_second_element(l: list);
var
    x: list;
begin
    { проверяем, что 2й элемент существует }
    if (l <> nil) and (l^.next <> nil) then begin
        x := l^.next;
        if x^.next <> nil then { если 2й элемент -- не последний -- испольуем его ссылку на след-й }
            l^.next := x^.next
        else { иначе -- удаляем ссылку }
            l^.next := nil;
        dispose(x);
    end;
end;

procedure pop(l: list);
var
    x: list;
begin
    if l <> nil then begin
        { находим предпоследний элемент. Он хранится в x }
        x := l;
        while l^.next <> nil do begin
            x := l;
            l := l^.next;
        end;
        dispose(x^.next); { очищаем память, выделенную под последний элемент }
        x^.next := nil { удаляем ссылку на последний элемент }
    end;
end;

procedure print_list(l: list);
var
    x: list;
begin
    while l <> nil do
    begin
        x := l^.next;
        write(l^.data, ' ');
        l := x;
    end;
    writeln;
end;

var
    head, node: list;
    i, n: integer;
begin
    { заполняем список }
    head := nil;
    write('Enter list length: ');
    readln(n);
    writeln('Enter list (one element per line)');
    for i:=1 to n do
    begin
        new(node);
        node^.next := head;
        readln(node^.data);
        head := node;
    end;

    Write('Input list is: ');
    print_list(head);

    { выполняем процедуры }
    write('List without 2dn element: ');
    remove_second_element(head);
    print_list(head);

    write('List without last element: ');
    pop(head);
    print_list(head);
end.
