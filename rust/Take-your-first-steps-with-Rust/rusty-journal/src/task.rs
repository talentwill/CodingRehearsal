use chrono::{serde::ts_seconds, DateTime, Utc};
use serde::{Deserialize, Serialize};

#[derive(Debug, Serialize, Deserialize)]
pub struct Task {
    text: String,
    #[serde(with = "ts_seconds")] // parse ts_seconds to serde's attribute,
    // so serde can know how the DataTime type will the two traits
    created_at: DateTime<Utc>,
}

impl Task {
    pub fn new(text: String) -> Self {
        Task {
            text,
            created_at: Utc::now(),
        }
    }
}
