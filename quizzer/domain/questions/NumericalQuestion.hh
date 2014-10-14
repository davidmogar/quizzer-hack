<?hh

require_once 'Question.hh';

class NumericalQuestion extends Question {
    private $correct;
    private $valueCorrect;
    private $valueIncorrect;

    public function __construct(int $id, string $text) {
        parent::__construct($id, $text);
    }

    public function getScore(Answer $answer): float {
        $score = 0;

        if (!empty($answer)) {
            if ($answer->getValue() == $this->correct) {
                $score = $this->valueCorrect;
            } else {
                $score = $this->valueIncorrect;
            }
        }

        return (float) $score;
    }

    public function getCorrect(): mixed {
        return $this->correct;
    }

    public function setCorrect(mixed $correct) {
        $this->correct = $correct;
    }

    public function getValueCorrect(): mixed {
        return $this->valueCorrect;
    }

    public function setValueCorrect(mixed $valueCorrect) {
        $this->valueCorrect = $valueCorrect;
    }

    public function getValueIncorrect():mixed {
        return $this->valueIncorrect;
    }

    public function setValueIncorrect(mixed $valueIncorrect) {
        $this->valueIncorrect = $valueIncorrect;
    }
}
