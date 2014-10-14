<?hh

class Grade {
  
    private $studentId;
    private $grade;

    public function __construct(int $studentId, float $grade) {
        $this->grade = $grade;
        $this->studentId = $studentId;
    }

    public function getGrade(): float {
        return $this->grade;
    }

    public function setGrade(float $grade) {
        $this->grade = $grade;
    }

    public function getStudentId():int {
        return $this->studentId;
    }

    public function setStudentId(int $studentId) {
        $this->studentId = $studentId;
    }
}
