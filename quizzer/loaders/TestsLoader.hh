<?hh

require_once 'quizzer/deserializers/TestsDeserializer.hh';

class TestsLoader {

    /**
     * Returns a list of tests objects loaded from the file referenced by the URL argument.
     *
     * @param $testsUrl URL to the tests file
     * @return array a list of tests objects
     * @throws Exception if there is an error while fetching content from the given URL
     */
    public static function loadTests(string $testsUrl): array {
        if (empty($testsUrl)) {
            throw new Exception('Tests URL cannot be null');
        }

        $testsJson = file_get_contents($testsUrl);

        return TestsDeserializer::deserialize($testsJson);
    }
}
