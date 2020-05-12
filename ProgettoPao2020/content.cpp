#include "content.h"

Content::Content(string _title, string _description, QDateTime _timestamp, content_type _type, vector<Stats_content> _stats) : title(_title), description(_description), timestamp(_timestamp), type(_type), stats(_stats){}
