__all__ = ["testset", "TestData"]
from dataclasses import dataclass
from typing import Optional


@dataclass
class TestData:
    C: list[float]
    A: list[list[float]]
    eps: float
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
        eps= 0.1
    ),
    interior=TestData(
        C= [1, 1, 0, 0], 
        A= [
            [2, 4, 1, 0],  
            [1, 3, 0, 1], 
        ],
        x= [2,1,1,-4],
        eps= 0.1
    )
)


testset = [
    test1,
]