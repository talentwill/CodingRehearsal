mod parent {
    pub fn a(){
        child::b();
    }
    mod child {

        fn b() {
            println!("b");
        }
    }
}


fn main() {
    parent::a();
}
