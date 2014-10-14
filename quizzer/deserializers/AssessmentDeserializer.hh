<?hh // decl

require_once 'quizzer/domain/Answer.hh';
require_once 'quizzer/domain/Grade.hh';
require_once 'quizzer/domain/questions/MultichoiceQuestion.hh';
require_once 'quizzer/domain/questions/TrueFalseQuestion.hh';

class AssessmentDeserializer {

    public static function deserializeAnswers(string $json): array {
        $data = json_decode($json);
        $answers = array();

        if (isset($data->items)) {
            foreach($data->items as $student) {
                if (isset($student->studentId) && isset($student->answers)) {
                    $studentAnswers = array();

                    foreach($student->answers as $answer) {
                        if (isset($answer->question) && isset($answer->value)) {
                            $studentAnswers[] = new Answer($answer->question, $answer->value);
                        }
                    }

                    $answers[$student->studentId] = $studentAnswers;
                }
            }
        }

        return $answers;
    }

    public static function deserializeGrades(string $json): array {
        $data = json_decode($json);
        $grades = array();

        if (isset($data->scores)) {
            foreach($data->scores as $grade) {
                if (isset($grade->studentId) && isset($grade->value)) {
                    $grades[$grade->studentId] = new Grade($grade->studentId, $grade->value);
                }
            }
        }

        return $grades;
    }

    public static function deserializeQuestions(string $json): array {
        $data = json_decode($json);
        $questions = array();

        if (isset($data->questions)) {
            foreach($data->questions as $question) {
                if (isset($question->type) && isset($question->id) && isset($question->questionText)) {
                    $newQuestion = null;

                    if ($question->type == 'multichoice') {
                        $newQuestion = self::createMultichoiceQuestion($question);
                    } else if ($question->type == 'numerical') {
                        $newQuestion = self::createNumericalQuestion($question);
                    } if ($question->type == 'truefalse') {
                        $newQuestion = self::createTruefalseQuestion($question);
                    }

                    if ($newQuestion != null) {
                        $questions[$question->id] = $newQuestion;
                    }
                }
            }
        }

        return $questions;
    }

    private static function createMultichoiceQuestion(mixed $question): MultichoiceQuestion {
        $multichoice = null;

        if (isset($question->alternatives)) {
            $multichoice = new MultichoiceQuestion($question->id, $question->questionText);
            foreach($question->alternatives as $alternative) {
                if (isset($alternative->text) && isset($alternative->code) && isset($alternative->value)) {
                    $multichoice->addAlternative($alternative->code, $alternative->text, $alternative->value);
                }
            }
        }

        return $multichoice;
    }

    private static function createNumericalQuestion(mixed $question): NumericalQuestion {
        $numerical = null;

        if (isset($question->correct) && isset($question->valueOK) && isset($question->valueFailed)) {
            $numerical = new NumericalQuestion($question->id, $question->questionText);
            $numerical->setCorrect($question->correct);
            $numerical->setValueCorrect($question->valueOK);
            $numerical->setValueIncorrect($question->valueFailed);

        }

        return $numerical;
    }

    private static function createTrueFalseQuestion(mixed $question): TrueFalseQuestion {
        $truefalse = null;

        if (isset($question->correct) && isset($question->valueOK) && isset($question->valueFailed)
                && isset($question->feedback)) {
            $truefalse = new TrueFalseQuestion($question->id, $question->questionText);
            $truefalse->setCorrect($question->correct);
            $truefalse->setValueCorrect($question->valueOK);
            $truefalse->setValueIncorrect($question->valueFailed);
            $truefalse->setFeedback($question->feedback);

        }

        return $truefalse;
    }
}
