% Define places with unique IDs
place(1, 'Admin Office').
place(2, 'Engineering BLD').
place(3, 'Library').
place(4, 'Cafeteria').
place(5, 'Lecture Hall A').
place(6, 'Institute Y').
place(7, 'Social Sciences BLD').
place(8, 'Institute X').

edge('Admin Office', 'Engineering BLD', 3).
edge('Engineering BLD', 'Admin Office', 3).

edge('Admin Office', 'Library', 1).
edge('Library', 'Admin Office', 1).

edge('Admin Office', 'Cafeteria', 4).
edge('Cafeteria', 'Admin Office', 4).

edge('Engineering BLD', 'Lecture Hall A', 2).
edge('Lecture Hall A', 'Engineering BLD', 2).

edge('Engineering BLD', 'Library', 5).
edge('Library', 'Engineering BLD', 5).

edge('Lecture Hall A', 'Institute Y', 3).
edge('Institute Y', 'Lecture Hall A', 3).

edge('Institute Y', 'Library', 3).
edge('Library', 'Institute Y', 3).

edge('Library', 'Cafeteria', 5).
edge('Cafeteria', 'Library', 5).

edge('Cafeteria', 'Social Sciences BLD', 2).
edge('Social Sciences BLD', 'Cafeteria', 2).

edge('Social Sciences BLD', 'Library', 2).
edge('Library', 'Social Sciences BLD', 2).

edge('Social Sciences BLD', 'Institute X', 8).
edge('Institute X', 'Social Sciences BLD', 8).


% Define delivery personnel
delivery_personnel(1, 10, [8, 12, 16, 20], none, 'Admin Office').
delivery_personnel(2, 8, [8, 12, 16, 20], delivering, 'Engineering BLD').
delivery_personnel(3, 12, [8, 12, 16, 20], none, 'Library').
% Add more personnel as needed

% Define objects to be delivered
object(101, 5, 'Admin Office', 'Engineering BLD', low, none).
object(102, 3, 'Engineering BLD', 'Lecture Hall A', medium, none).
object(103, 7, 'Library', 'Cafeteria', high, 2).
object(104, 4, 'Social Sciences BLD', 'Library', medium, none).
object(105, 6, 'Admin Office', 'Institute X', high, none).
% Add more objects as needed


travel_time(Place1, Place2, Time) :- shortest_path(Place1, Place2, _, Time).

find_shortest_path(End, End, Path, Path, 0).

find_shortest_path(Start, End, TempPath, Path, Length) :-
    length(TempPath, CurrentLength),
    CurrentLength < 4,
    edge(Start, Next, Time),
    \+ member(Next, TempPath),
    find_shortest_path(Next, End, [Next|TempPath], Path, RestLength),
    Length is RestLength + Time.

shortest_path(Start, End, ShortestPath, ShortestLength) :-
    setof([Path, Length], find_shortest_path(Start, End, [Start], Path, Length), Paths),
    find_shortest(Paths, ShortestPath, ShortestLength).

find_shortest([[Path, Length] | RestPaths], ShortestPath, ShortestLength) :-
    find_shortest(RestPaths, Path, Length, ShortestPath, ShortestLength).

find_shortest([], ShortestPath, ShortestLength, ShortestPath, ShortestLength).
find_shortest([[Path, Length] | RestPaths], CurrShortestPath, CurrShortestLength, ShortestPath, ShortestLength) :-
    (Length < CurrShortestLength ->
        find_shortest(RestPaths, Path, Length, ShortestPath, ShortestLength)
    ;
        find_shortest(RestPaths, CurrShortestPath, CurrShortestLength, ShortestPath, ShortestLength)
    ).



% Nesnenin taşınıp taşınmadığını kontrol eden ve gerekli duruma göre işlem yapan fonksiyon
check_delivery(ObjectID) :-
    object(ObjectID, _, Start, End, _, Status),
    (Status \= none ->
        % Nesne taşınıyor, taşıyan personelin ID'sini bul ve yazdır
        find_delivering_person(ObjectID, DeliveringPersonID),
        write('Nesneyi tasiyan personel ID: '), write(DeliveringPersonID), nl
    ;
        % Nesne taşınmıyor, boşta olan personellerin nesneyi taşıyıp taşıyamayacağını kontrol et
        find_idle_personnel(Start, End, ObjectID, DeliveryTime , PersonID),
        (DeliveryTime > 0 ->
            % Eğer boşta olan bir personel varsa, taşıma süresini bastır
            write('Nesneyi tasima suresi: '), write(DeliveryTime), write(' dakika.'), write('Personal ID '), write(PersonID),nl
        ;
            % Eğer boşta olan personel yoksa
            write('Boşta olan personel bulunamadı. Nesneyi taşıyacak kimse yok.'), nl
        )
    ).

find_delivering_person(ObjectID, DeliveringPersonID) :-
    object(ObjectID, _, _, _, _, DeliveringPersonID),
    DeliveringPersonID \= none.

delivering_or_busy_person(PersonID) :-
    delivery_personnel(PersonID, _, _, Status, _),
    Status \= delivering.

find_idle_personnel(Start, End, ObjectID, DeliveryTime,PersonID) :-
    object(ObjectID, Weight, Start, End, _, _),  % Nesnenin weight değerini al
    delivery_personnel(PersonID, Capacity, _, none, CurrentLocation),
    Capacity >= Weight,  % Kapasite ile nesnenin weight değerini karşılaştır
    delivering_or_busy_person(PersonID),
    travel_time(CurrentLocation, Start, Time1),
    travel_time(Start, End, Time2),
    DeliveryTime is Time1 + Time2.










