<?hh

require_once 'quizzer/loaders/AssessmentLoader.hh';

class AssessmentLoaderTest extends PHPUnit_Framework_TestCase {

    private static $questionsUrl = 'tests/resources/questions.json';
    private static $answersUrl = 'tests/resources/answers.json';
    private static $gradesUrl = 'tests/resources/grades.json';

    public function testLoadAssessmentFromUrls() {
        $this->assertTrue(file_exists(self::$questionsUrl), "Missing questions file");
        $this->assertTrue(file_exists(self::$answersUrl), "Missing answers file");
        $this->assertTrue(file_exists(self::$gradesUrl), "Missing grades file");

        try {
            AssessmentLoader::loadAssessmentFromUrls(self::$questionsUrl, self::$answersUrl, self::$gradesUrl);
            AssessmentLoader::loadAssessmentFromUrls(self::$questionsUrl, self::$answersUrl, "");
        } catch(Exception $e) {
            $this->fail('Exception not expected');
        }
    }
}
