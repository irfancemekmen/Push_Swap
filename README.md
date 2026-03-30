*This project has been created as part of the 42 curriculum by iekmen.*

# Push_swap

## Description
**Push_swap**, verilerin bir yığın (stack) üzerinde kısıtlı bir komut seti kullanılarak, mümkün olan en az hamleyle sıralanmasını hedefleyen bir algoritma projesidir. Proje kapsamında, rastgele sayılardan oluşan bir yığını (stack a) artan düzende sıralamak için en uygun algoritmaların seçilmesi ve uygulanması beklenmektedir.

### The Rules
İki adet yığın (a ve b) ve bunları manipüle etmek için belirli operasyonlar kullanılır:
* **sa/sb/ss**: Yığının en üstündeki ilk iki elemanı yer değiştirir.
* **pa/pb**: Bir yığının tepesindeki elemanı alıp diğer yığının tepesine koyar.
* **ra/rb/rr**: Yığındaki tüm elemanları 1 pozisyon yukarı kaydırır; ilk eleman sonuncu olur.
* **rra/rrb/rrr**: Yığındaki tüm elemanları 1 pozisyon aşağı kaydırır; son eleman birinci olur.

---

## Instructions

### Compilation
Proje, `cc` derleyicisi ve `-Wall -Wextra -Werror` bayrakları kullanılarak bir `Makefile` aracılığıyla derlenmelidir[cite: 102]. `Makefile` en az şu kuralları içermelidir: `$(NAME)`, `all`, `clean`, `fclean` ve `re`[cite: 104].

```bash
make
```

## Usage
Program, argüman olarak bir tam sayı listesi alır. İlk argüman yığının en üstünde yer alır.

```bash
./push_swap 2 1 3 6 5 8
```
Hata Yönetimi:
Geçersiz argümanlar (tam sayı olmayanlar, tam sayı limitini aşanlar veya mükerrer sayılar) durumunda, standart hataya Error yazdırılır.

### Benchmarks
Maksimum puan (%100) için programın şu sınırları aşmaması gerekir:
- 100 rastgele sayı: 700 operasyondan az.
- 500 rastgele sayı: 5500 operasyondan fazla değil.

## Resources

### References
- Sorting Algorithms: Algoritmik karmaşıklık ve sıralama yöntemleri üzerine araştırmalar.

### AI Usage
Bu projede Yapay Zeka (AI) kullanımı aşağıdaki kurallar çerçevesinde gerçekleştirilmiştir:
- Kullanılan Alanlar: Parser tasarımı ve test senaryolarının oluşturulması aşamalarında fikir alışverişi yapılmıştır.
- Etik Kullanım: AI araçları tekrarlayan görevleri hızlandırmak için kullanılmış, ancak karmaşık algoritma kararları ve projenin özgünlüğü korunmuştur.
