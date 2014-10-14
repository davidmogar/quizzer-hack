<?hh

class Answer {
    private $questionId;
    private $value;

    public function __construct(int $questionId, mixed $value) {
        $this->questionId = $questionId;
        $this->value = $value;
    }

    public function getQuestionId(): int {
        return $this->questionId;
    }

    public function setQuestionId(int $questionId) {
        $this->questionId = $questionId;
    }

    public function getValue(): mixed {
        return $this->value;
    }

    public function setValue(mixed $value) {
        $this->value = $value;
    }
}
