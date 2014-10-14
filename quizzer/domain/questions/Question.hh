<?hh

require_once 'quizzer/domain/Answer.hh';

abstract class Question
{
    protected $text;
    protected $id;

    public function __construct($id, $text)
    {
        $this->id = $id;
        $this->text = $text;
    }

    abstract public function getScore(Answer $answer);

    public function getId()
    {
        return $this->id;
    }

    public function setId($id)
    {
        $this->id = $id;
    }

    public function getText()
    {
        return $this->text;
    }

    public function setText($questionText)
    {
        $this->text = $questionText;
    }
}
