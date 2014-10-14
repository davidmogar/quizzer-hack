<?hh

class Test {
    private $questionsUrl;
    private $answersUrl;
    private $gradesUrl;

    public function __construct(string $questionsUrl, string $answersUrl,
            string $gradesUrl) {
        $this->questionsUrl = $questionsUrl;
        $this->answersUrl = $answersUrl;
        $this->gradesUrl = $gradesUrl;
    }

    public function getAnswersUrl(): string {
        return $this->answersUrl;
    }

    public function setAnswersUrl(string $answersUrl) {
        $this->answersUrl = $answersUrl;
    }

    public function getGradesUrl(): string {
        return $this->gradesUrl;
    }

    public function setGradesUrl(string $gradesUrl) {
        $this->gradesUrl = $gradesUrl;
    }

    public function getQuestionsUrl(): string {
        return $this->questionsUrl;
    }

    public function setQuestionsUrl(string $questionsUrl) {
        $this->questionsUrl = $questionsUrl;
    }
}
