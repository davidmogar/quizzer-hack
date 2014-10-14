<?hh

require_once 'quizzer/deserializers/TestsDeserializer.hh';

class TestsLoader {

    public static function loadTests(string $testsUrl): array {
        if (empty($testsUrl)) {
            throw new Exception('Tests URL cannot be null');
        }

        $testsJson = file_get_contents($testsUrl);

        return TestsDeserializer::deserialize($testsJson);
    }
}
