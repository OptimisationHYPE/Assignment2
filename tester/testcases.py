__all__ = ["testset", "TestData"]
from dataclasses import dataclass
from typing import Optional


@dataclass
class TestData:
    C: list[float]
    A: list[list[float]]
    eps: float = 0.1
    x: Optional[list[float]] = None
    b: Optional[list[float]] = None
    alpha: Optional[float] = None

    def __repr__(self) -> str: # Unified converter to str (used for same interior and simplex)
        # C A (x) (b) eps (alph) - order of input
        # () - optional fields will enter input only if not None
        stringify = ""
        stringify += ' '.join([str(_) for _ in self.C]) + '\n\n'
        for line in self.A:
            stringify += ' '.join([str(_) for _ in line]) + '\n'
        stringify += "\n"
        if self.x: stringify += ' '.join([str(_) for _ in self.x]) + '\n\n'
        if self.b: stringify += ' '.join([str(_) for _ in self.b]) + '\n\n'
        stringify += str(self.eps) + '\n'
        if self.alpha: stringify += str(self.alpha) + '\n'
        return stringify
    
@dataclass
class TestPair:
    simplex: TestData
    interior: TestData

test1 = TestPair(
    simplex=TestData(
        C= [1,1], 
        A= [
            [2,4],  
            [1,3], 
        ],
        b= [16, 9],
    ),
    interior=TestData(
        C= [1, 1, 0, 0], 
        A= [
            [2, 4, 1, 0],  
            [1, 3, 0, 1], 
        ],
        x= [2,1,1,-4],
    )
)

test2 = TestPair(
    simplex=TestData(
        C= [-9, 2, -4], 
        A= [
            [2, 4, 1],  
            [3, -3, 4],
            [5, 2, -1],  
        ],
        b= [6, 3, 7],
    ),
    interior=TestData(
        C= [-9, 2, -4, 0, 0, 0], 
        A= [
            [2, 4, 1, 1, 0, 0],  
            [3, -3, 4, 0, 1, 0],
            [5, 2, -1, 0, 0, 1],  
        ],
        x= [1, 3, 2, 4, 5, 2],
    )
)

test3 = TestPair(
    simplex=TestData(
        C= [3, 1], 
        A= [
            [2, 1],  
            [1, 2],
        ],
        b= [6, 4],
    ),
    interior=TestData(
        C= [3, 1, 0, 0], 
        A= [
            [2, 1, 1, 0],  
            [1, 2, 0, 1],
        ],
        x= [1, 1, 1, 1],
    )
)
test4 = TestPair(
    simplex=TestData(
        C= [9, 10, 16], 
        A= [
            [18, 15, 12],  
            [6, 4, 8],
            [5, 3, 3],
        ],
        b = [360, 192, 180]
    ),
    interior=TestData(
        C= [9, 10, 16, 0, 0, 0], 
        A= [
            [18, 15, 12, 1, 0, 0],  
            [6, 4, 8, 0, 1, 0],
            [5, 3, 3, 0, 0, 1],
        ],
        x= [3, 2, 4, 1, .5, 4],
    )
)
test5 = TestPair(
    simplex=TestData(
        C= [-1, 1], 
        A= [
            [1, 2],  
            [2, 1],
        ],
        b = [20, 20]
    ),
    interior=TestData(
        C= [-1, 1, 0, 0], 
        A= [
            [1, 2, 1, 0],  
            [2, 1, 0, 0],
        ],
        x= [.1, .1, .1, .1],
    )
)


testset = [
    test1,
    test2,
    test3,
    test4,
    test5
]