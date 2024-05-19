#include <stdio.h>
#include <time.h>

void millisToDatetime(long long milliseconds) {
    time_t seconds = milliseconds / 1000;
    struct tm *datetime = localtime(&seconds);

    // 输出日期和时间信息
    printf("\n转换后的日期和时间为：%d-%02d-%02d %02d:%02d:%02d\n",
           datetime->tm_year + 1900, datetime->tm_mon + 1, datetime->tm_mday,
           datetime->tm_hour, datetime->tm_min, datetime->tm_sec);
}

int main() {
    printf("\n起始时间2024.3.30，输入操作码：1表示加，2表示减,3为退出：");
    for (;;) {
        long long currentTime = 1711804190489LL; // 使用LL后缀确保常量被识别为long long类型
        long long date2 = 86400000LL; // 一天的毫秒数
        int code, days;

        scanf("%d", &code);
        if (code == 3) {
            break;
        }
        switch (code) {
            case 1:
                printf("请输入要加的天数：");
                scanf("%d", &days);
                currentTime += days * date2;
                printf("时间为：%lld\n", currentTime);
                printf("加10分钟为：%lld\n", currentTime + 600000);

                millisToDatetime(currentTime);
                break;

            case 2:
                printf("请输入要减的天数：");
                scanf("%d", &days);
                currentTime -= days * date2;
                printf("时间为：%lld\n", currentTime);
                printf("加10分钟为：%lld\n", currentTime + 600000);

                millisToDatetime(currentTime);
                break;

            default:
                printf("无效的操作码。\n");
                break;
        }
    }
    return 0;
}

