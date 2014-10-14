<?hh

require_once 'quizzer/Assessment.hh';
require_once 'quizzer/deserializers/AssessmentDeserializer.hh';

class AssessmentLoader {

    public static function loadAssessmentFromUrls(string $questionsUrl,
            string $answersUrl, ?string $gradesUrl): Assessment {
        if (!isset($questionsUrl) || !isset($answersUrl)) {
            throw new Exception('Questions and answers URLs cannot be null');
        }

        $questionsJson = file_get_contents($questionsUrl);
        $answersJson = file_get_contents($answersUrl);

        $gradesJson = null;
        if (!empty($gradesUrl)) {
            $gradesJson = file_get_contents($gradesUrl);
        }

        return self::createAssessment($questionsJson, $answersJson, $gradesJson);
    }

    public static function loadAssessmentFromJsons(string $questionsJson,
            string $answersJson, ?string $gradesJson): Assessment {
        if (!isset($questionsJson) || !isset($answersJson)) {
            throw new Exception('Questions and answers URLs cannot be null');
        }

        return self::createAssessment($questionsJson, $answersJson, $gradesJson);
    }

    private static function createAssessment(string $questionsJson,
            string $answersJson, ?string $gradesJson): Assessment {
        $assessment = new Assessment();

        $assessment->setQuestions(AssessmentDeserializer::deserializeQuestions($questionsJson));
        $assessment->setAnswers(AssessmentDeserializer::deserializeAnswers($answersJson));

        if (!empty($gradesJson)) {
            $assessment->setGrades(AssessmentDeserializer::deserializeGrades($gradesJson));
        }

        return $assessment;
    }
}
