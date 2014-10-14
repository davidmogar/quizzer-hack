<?hh

require_once 'Question.hh';

class MultichoiceQuestion extends Question {

    private $alternatives;

    function __construct(int $id, string $text) {
        parent::__construct($id, $text);

        $this->alternatives = array();
    }

    function addAlternative(int $id, string $text, mixed $value) {
        $this->alternatives[$id] = new Alternative($id, $text, $value);
    }

    public function getScore(Answer $answer): float {
        $score = 0;

        if (!empty($answer)) {
            $answerValue = $answer->getValue();

            if (isset($this->alternatives[$answerValue])) {
                $score = $this->alternatives[$answerValue]->value;
            }
        }

        return (float) $score;
    }
}

class Alternative {
    var $id;
    var $text;
    var $value;

    function __construct(int $id, string $text, mixed $value) {
        $this->id = $id;
        $this->text = $text;
        $this->value = $value;
    }
}
