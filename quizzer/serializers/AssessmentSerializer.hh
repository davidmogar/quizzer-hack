<?hh

require_once "quizzer/serializers/AssessmentJsonSerializer.hh";
require_once "quizzer/serializers/AssessmentXmlSerializer.hh";

class AssessmentSerializer {

    /**
     * Returns an string with the representation of the grades in the desired format.
     *
     * @param $grades grades to serialize
     * @param $format format of the output
     * @return null|string an string with the representation in the desired format
     */
    public static function serializeGrades(array $grades, string $format): string {
        $result = "";

        switch (strtolower($format)) {
            case 'xml':
                $result = AssessmentXmlSerializer::serializeGrades($grades);
                break;
            default: /* Json */
                $result = AssessmentJsonSerializer::serializeGrades($grades);
        }

        return $result;
    }

    /**
     * Returns an string with the representation of the statistics in the desired format.
     *
     * @param $statistics statistics to serialize
     * @param $format format of the output
     * @return null|string an string with the representation in the desired format
     */
    public static function serializeStatistics(array $statistics, string $format): string {
        $result = "";

        switch (strtolower($format)) {
            case 'xml':
                $result = AssessmentXmlSerializer::serializeStatistics($statistics);
                break;
            default: /* Json */
                $result = AssessmentJsonSerializer::serializeStatistics($statistics);
        }

        return $result;
    }
}
