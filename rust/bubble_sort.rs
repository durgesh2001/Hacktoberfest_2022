fn bubble_sort<T: Ord>(array: &mut[T]) {
    for i in 0..array.len() {
        for j in 0..array.len() - 1 - i {
            if array[j] > array[j + 1] {
                array.swap(j, j + 1)
            }
        }
    }
}

#[test]
fn test_i32() {
    let mut numbers: [i32; 5] = [0, 5, 2, 3, 2];
    let results: [i32; 5] = [0, 2, 2, 3, 5];
    bubble_sort(&mut numbers);
    assert_eq!(numbers, results);
}


#[test]
fn test_strings() {
    let mut strings: [&str; 5] = ["d", "a", "b", "e", "c"];
    let results: [&str; 5] = ["a", "b", "c", "d", "e"];
    bubble_sort(&mut strings);
    assert_eq!(strings, results);
}
