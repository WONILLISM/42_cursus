# printf

This project is pretty straight forward. You will recode printf. Hopefully you will be able to reuse it in future project without the fear of being flagged as a cheater. You will mainly learn how to use variadic arguments.

putnbr과 putstr만으로는 충분하지 않기 때문에

요약: 이 프로젝트는 꽤 간단합니다. 여러분은 printf 함수를 다시 구현할 것입니다. 희망컨대 여러분들은 cheating의 두려움 없이 추후 프로젝트에서 ft_printf를 재사용할 수 있습니다.

여러분들은 주로 가변 인자(variadic arguments)를 사용하는 방법에 대해 배울 것입니다.

사용언어 : c언어

## :blue_book: 작성 규칙
+ 프로젝트는 Norm 규칙에 맞춰 작성되어야 합니다. 보너스 파일/함수가 있는 경우,해당 파일/함수 들은 norm 검사에 포함되며, norm error가 있을 시, 0점을 받게 될것입니다.
+ 함수들은 정의되지 않은 행동들과는 별개로 예기치 않게 중단되어서는 안 됩니다.(예를 들어, segmentation fault, bus error, double free 등.) 만약 이렇게 중단되면, 여러분의 프로젝트는 작동하지 않는 것으로 여겨지고 평가에서 0점을 받을 것입니다.
+ 필요한 경우 heap에 할당된 모든 메모리 공간은 적절하게 해제되어야 합니다. 메모리 누수는 용납되지 않습니다.
+ 해당 과제에서 요구한 경우 Makefile 을 제출해야하며, 해당 Makefile은 문제에서 제시된 결과물을 -Wall -Wextra -Werror 플래그과 함께 컴파일해야합니다. Makefile 은 relink 되어서는 안 됩니다.
+ Makefile은 최소한 $(NAME), all, clean, fclean, re 규칙을 포함해야 합니다.
+ 프로젝트에 보너스를 제출하려면, Makefile에 bonus 규칙을 포함해야하며, 해당 규칙은 프로젝트의 메인 파트에서 금지되었던 모든 다양한 헤더, 라이브러리,또는 함수들을 Makefile에 추가할 수 있습니다. 보너스는 반드시 _bonus.{c/h} 라는 다른 파일에 있어야 합니다. 필수 파트와 보너스 파트는 개별적으로 평가될 것입니다.
+ 프로젝트에서 libft 사용이 허가된 경우, 해당 소스들과 연관된 Makefile을 libft 폴더에 Makefile과 함께 복사해 넣어두어야 합니다. 프로젝트의 Makefile은 반드시 libft 의 Makefile을 사용하여 컴파일한 다음, 프로젝트 소스를 컴파일 해야만 합니다.
+ 제출할 필요가 없고 채점되지 않더라도 우리는 여러분이 프로젝트를 위한 테스트 프로그램을 만들 것을 권장합니다. 이 프로그램은 여러분의 과제물과 동료들의 과제물을 쉽게 검증할 기회를 제공할 것입니다. 평가하는 동안 이 테스트 프로그램들이 특히 유용하다는 것을 알게 될 것입니다. 평가 중에는 여러분의 테스트 프로그램과 평가 받는 동료의 테스트 프로그램들을 자유롭게 사용할 수 있습니다.
+ 할당된 git 저장소에 과제물을 제출하세요. 오직 git 저장소에 있는 과제물만 채점 할 것입니다. Deepthought가 평가를 하게 된다면, 동료평가 이후에 수행됩니다. 만약 Deepthought가 평가 중 오류가 발생한다면, 그 즉시 평가는 중지될 것입니다.

## :blue_book: Mandatory Part(필수 요소)

| Program name     | libftprintf.a                                                |
| ---------------- | ------------------------------------------------------------ |
| Turn in files    | *.c, */*.c, *.h, */*.h, Makefile                             |
| Makefile         | all, clean, fclean, re, bonus                                |
| External functs. | malloc, free, write, va_start, va_arg, va_copy, va_end       |
| Libft authorized | yes                                                          |
| Description      | 실제 printf의 모방 함수인 ft_printf가 포함된 라이브러리를 작성하십시오 |


+ ft_printf의 프로토타입은 int ft_printf(const char , …); 이어야 합니다.
+ 당신은 libc의 printf 함수를 다시 구현해야 합니다.
+ 실제 printf 함수처럼 버퍼 관리를 수행해서는 안 됩니다.
+ 다음과 같은 서식 지정자들을 구현할 것입니다: cspdiuxX%
+ 모든 서식문자에서 ‘-0.*’ 플래그와 최소 필드 너비의 조합을 어떤 조합도 처리할 것입니다.
+ 실제 printf 함수와 비교될 것입니다.

## :blue_book: Bonus Part

Bonus part

* 만약 필수적으로 해야하는 부분들이 완벽하지 않다면, 보너스에 대해서는 생각조차 안 할 것입니다.
* 보너스를 모두 구현할 필요는 없습니다.
* 다음 서식 지정자 중 하나 이상을 구현하십시오 : nfge
* 다음 플래그 중 하나 이상을 구현하십시오 : l ll h hh
* 다음 플래그를 모두 구현하십시오 : '# +' (플래그 중 하나는 공백이 맞습니다.)
