<?hh

require_once "quizzer/serializers/AssessmentJsonSerializer.hh";
require_once "quizzer/serializers/AssessmentXmlSerializer.hh";

class AssessmentSerializer
{
    public static function serializeGrades($grades, $format)
    {
        $result = null;

        switch (strtolower($format)) {
            case 'xml':
                $result = AssessmentXmlSerializer::serializeGrades($grades);
                break;
            default: /* Json */
                $result = AssessmentJsonSerializer::serializeGrades($grades);
        }

        return $result;
    }

    public static function serializeStatistics($statistics, $format)
    {
        $result = null;

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
