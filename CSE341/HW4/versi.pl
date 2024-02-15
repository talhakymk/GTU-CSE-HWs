% Define the classify predicate
classify(SepalLength, SepalWidth, PetalLength, PetalWidth, Class) :-
    (   PetalLength =< 2.45
    ->  Class = 'Iris-setosa'
    ;   PetalWidth =< 1.75
    ->  (   PetalLength =< 4.95
        ->  (   PetalWidth =< 1.65
            ->  Class = 'Iris-versicolor'
            ;   Class = 'Iris-virginica'
            )
        ;   (   PetalWidth =< 1.55
            ->  Class = 'Iris-virginica'
            ;   Class = 'Iris-versicolor'
            )
        )
    ;   Class = 'Iris-virginica'
    ).

% Example query
% classify(4.9, 2.4, 3.3, 1.0, Class).