<?hh

class AssessmentJsonSerializer {

    /**
     * Returns an string with the representation of the grades in JSON format.
     *
     * @param $grades grades to serialize
     * @return string an string with the representation in the desired format.
     */
    public static function serializeGrades(array $grades): string {
        $scores = array();

        foreach ($grades as $studentId => $grade) {
            $score = array(
                "studentId" => $studentId,
                "value" => $grade->getGrade()
            );
            $scores[] = $score;
        }

        return '{"scores": ' . json_encode($scores, JSON_PRETTY_PRINT) . '}';
    }

    /**
     * Returns an string with the representation of the statistics in JSON format.
     *
     * @param $statistics statistics to serialize
     * @return string an string with the representation in the desired format.
     */
    public static function serializeStatistics(array $statistics): string {
        $items = array();

        foreach ($statistics as $questionId => $value) {
            $item = array(
                "questionId" => $questionId,
                "correctAnswers" => $value
            );
            $items[] = $item;
        }

        return '{"items": ' . json_encode($items, JSON_PRETTY_PRINT) . '}';
    }
}
