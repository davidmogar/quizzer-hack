<?hh

require_once 'quizzer/domain/Answer.hh';

abstract class Question {
    protected $text;
    protected $id;

    public function __construct(int $id, string $text) {
        $this->id = $id;
        $this->text = $text;
    }

    abstract public function getScore(Answer $answer): float;

    public function getId(): int {
        return $this->id;
    }

    public function setId(int $id) {
        $this->id = $id;
    }

    public function getText(): string {
        return $this->text;
    }

    public function setText(string $questionText) {
        $this->text = $questionText;
    }
}
