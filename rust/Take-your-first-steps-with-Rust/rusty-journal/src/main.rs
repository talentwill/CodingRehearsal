use structopt::StructOpt;
use crate::cli::Action::*;
use crate::cli::CommandLineArgs;
use crate::task::Task;

mod cli;
mod task;

fn main() {
    // Destructure, the fields can be used independently
    let CommandLineArgs {
        action,
        journal_file,
    } = CommandLineArgs::from_args();

    // Unpack the journal file
    let journal_file = journal_file.expect("Failed to find a journal file");

    // Perform the actions
    match action {
        Add{text} => task::add_task(journal_file, Task::new(text)),
        Done {position} => task::complete_task(journal_file, position),
        List => task::list_tasks(journal_file),
    }.expect("Failed to perform action")
}
