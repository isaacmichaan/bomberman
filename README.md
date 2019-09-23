# bomberman
Bomberman Game
בס"ד
PROJECT-OOP1-BOMBERMAN

יצחק משען-fs891243
308362425  בנימין גולדשטיין
מוטי בלוך-038219812
תיאור התוכנית:
התוכנית מציגה את המשחק בומברמן.
בומברמן הוא רובוט שמנסה לברוח מהמפעל וצריך להיזהר מהשומרים שיש בדרך ורוצים לתפוס אותו.
הוא יכול להרוג את השומרים עם פצצות, אך צריך להיזהר לא להיפגע מהם בעצמו.
יש שומרים חכמים ויש שומרים שאינם חכמים.
השומרים שאינם חכמים זזים באופן רנדומלי על הלוח, והשומרים החכמים זזים על הלוח במטרה למצוא את המקום הכי קרוב אל הרובוט, לפי האלגוריתם של "מרחק מנהטן" שאותו נסביר בקובץ של השומרים החכמים.
הרובוט יכול לאסוף מתנות שיש על הלוח, חלקם טובים יותר וחלקם פחות, כמו האפשרות להוסיף חיים או להוריד חיים, כמו כן הוא יכול להוסיף לו פצצות שמוגבלות בתחילת השלב.
לרובוט יש מספר צעדים מוגבל לכל שלב, והוא יכול להשתמש בהם עד תומם, ואחרי שהם יגמרו ירדו לו חיים.

קבצים:
Board.h/cpp:
זה קובץ שבו מבוצעים כל הדברים שקשורים ללוח, ההשמה של האובייקטים על הלוח והפתיחה של הלוח.
Bomb.h/cpp:
המחלקה של הפצצה יורשת מהאובייקטים שלא זזים, שם אנו מקבלים את הפצצה ובודקים האם הפצצה פגעה ברובוט או בשומר (ע"י דאבל דיספאץ').
Comtroller.h/cpp:
המחלקה שאחראית על תפעול המשחק, כל מה שיש במשחק עובר אצלה.
אצלה יוצא התמונות של תחילת המשחק סוף המשחק וניצחון המשחק, ושם יש את הקריאה של הקבצים והפתיחה שלהם.
Door.h/cpp:
המחלקה של הדלת יורשת מהאובייקטים שלא זזים, וכל מה שהיא עושה זה לראות התנגשות של הרובוט עם הדלת.
gameObjet.h/cpp:
המחלקה של כל האובייקטים שיש במשחק, היא אחראית על כל מה שיש במשחק, ומורישה הרבה תכונות לכל האובייקטים.
מחלקה זו היא מחלקה אבסטרקטית טהורה.
Gipt.h/cpp:
המחלקה יורשת מהאובייקטים שלא זזים, היא מורישה לכל המתנות שיש במשחק את המיקום, ולכל מתנה יש דברים מיוחדים משלה.
Guard.h/cpp:
המחלקה הזו יורשת מהמחלקה של האובייקטים הזזים, היא אחראית על השומרים ומזיזה אותם בצורה רנדומלית, היא גם מורישה למחלקה של השומר החכם.
המחלקה גם אחראית על ההתנגשות של השומר עם הרובוט בכדי לגרום לפסילה של הרובוט.
inpoBar.h/cpp:
המחלקה הזו דואגת להראות לנו כמה חיים יש לרובוט, איזה שלב אנחנו, כמה פצצות וצעדים נשאר לנו וכמה זמן נשאר עד לסיום השלב.
MoveObject.h/cpp:
המחלקה הזו יורשת מהמחלקה של האובייקטים של המשחק, המחלקה הזו אחראית על התזוזות של האבייקטים במשחק.
Robot.h/cpp:
המחלקה הזו יורשת מהאובייקטים הזזים, היא אחראית על הרובוט ובודקת אם הוא יכול לזוז, והאם הוא נתקע באיזה מקום כך שהוא צריך להיפסל ולרדת לו חיים.
rock.h/cpp:
המחלקה הזו יורשת מהאובייקטים שלא זזים, היא אחראית על הסלעים ובודקת אם זה מתפוצץ שיש פצצה.
SmartGuard.h/cpp:
המחלקה הזו יורשת מהשומר הרגיל ורק משנה את התזוזה שלו שיהיה חכם.
התזוזה מתבצעת לפי האלגוריתם של "מרחק מנהטן" שבו אנו בודקים האם עדיף לרדוף אחרי הרובוט ימינה או שמאלה למטה או למעלה לפי הערך המוחלט של המרחק, ואז זז לכיוון הכי נח לו.
StaticObject.h/cpp:
המחלקה של האובייקטים שלא זזים, היא יורשת מהמחלקה של האחראי על האובייקטים במשחק והוא בודק האם יש התנגשות של דברים עם הרובוט או השומר.
Timed.h/cpp:
המחלקה הזו יורשת מהדברים שלא זזים, והיא אחראית על הזמן של המשחק, ושל תזוזת האובייקטים.
tipeB/L/k.h/cpp:
מחלקות שיורשות מהמתנה, והם המתנות עצמם, יש חיים נוספים, יש עוד פצצות ויש שמוריד חיים.
Utilities.h:
שומר את כל המשתנים הגלובלים שיש בשביל לדעת מה צריך לשנות.
Wall.h/cpp:
מחלקה שיורשת מאובייקטים שלא זזים, והיא אחראית על הקירות שמסביב למשחק, ואם יש גם בתוך הלוח היא אחראית עליהם, שלא יהרסו על ידי פצצות, ולא יתנו לאף אחד לזוז מחוץ לגבולות של השלב.
באגים ידועים:
כאשר הפצצה מתפוצצת היא לא סופרת לאחור.
הפצצה לא תמיד מפוצצת את כל מה שהיא אמורה לפוצץ.


